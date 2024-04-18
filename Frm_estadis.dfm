object Form_estadis: TForm_estadis
  Left = 193
  Top = 179
  Width = 894
  Height = 488
  Caption = 'Estadísticas Avanzadas'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object dbgrd_estadis: TdxDBGrid
    Left = 0
    Top = 94
    Width = 878
    Height = 355
    Bands = <
      item
      end>
    DefaultLayout = False
    HeaderPanelRowCount = 1
    KeyField = 'LLAVE'
    ShowGroupPanel = True
    ShowSummaryFooter = True
    SummaryGroups = <
      item
        DefaultGroup = False
        SummaryItems = <
          item
            ColumnName = 'dbgrd_estadisENE'
            SummaryField = 'ENE'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisFEB'
            SummaryField = 'FEB'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisMAR'
            SummaryField = 'MAR'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisABR'
            SummaryField = 'ABR'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisMAY'
            SummaryField = 'MAY'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisJUN'
            SummaryField = 'JUN'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisJUL'
            SummaryField = 'JUL'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisAGO'
            SummaryField = 'AGO'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisSEP'
            SummaryField = 'SEP'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisOCT'
            SummaryField = 'OCT'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisNOV'
            SummaryField = 'NOV'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisDIC'
            SummaryField = 'DIC'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisTOT'
            SummaryField = 'TOT'
            SummaryFormat = '0'
            SummaryType = cstSum
          end>
        Name = 'dbgrd_estadisSummaryGroup2'
      end
      item
        DefaultGroup = False
        SummaryItems = <
          item
            ColumnName = 'dbgrd_estadisENE'
            SummaryField = 'ENE'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisFEB'
            SummaryField = 'FEB'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisMAR'
            SummaryField = 'MAR'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisABR'
            SummaryField = 'ABR'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisMAY'
            SummaryField = 'MAY'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisJUN'
            SummaryField = 'JUN'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisJUL'
            SummaryField = 'JUL'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisAGO'
            SummaryField = 'AGO'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisSEP'
            SummaryField = 'sep'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisOCT'
            SummaryField = 'OCT'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisNOV'
            SummaryField = 'NOV'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisDIC'
            SummaryField = 'DIC'
            SummaryFormat = '0'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_estadisTOT'
            SummaryField = 'TOT'
            SummaryFormat = '0'
            SummaryType = cstSum
          end>
        Name = 'dbgrd_estadisSummaryGroup3'
      end>
    SummarySeparator = ', '
    Align = alClient
    PopupMenu = PopupMenu1
    TabOrder = 0
    DataSource = dts_estadis
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsBehavior = [edgoAutoCopySelectedToClipboard, edgoAutoSort, edgoDragScroll, edgoEditing, edgoEnterShowEditor, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    ShowRowFooter = True
    OnCustomDrawCell = dbgrd_estadisCustomDrawCell
    object dbgrd_estadisCODIGO: TdxDBGridMaskColumn
      Caption = 'Código'
      Width = 70
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODIGO'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
    object dbgrd_estadisDESCRI: TdxDBGridMaskColumn
      Caption = 'Descripción'
      Width = 39
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
    object dbgrd_estadisALM: TdxDBGridMaskColumn
      Caption = 'Alm'
      Width = 39
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ALM'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
    object dbgrd_estadisENE: TdxDBGridMaskColumn
      Caption = 'Ene'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ENE'
      SummaryFooterType = cstSum
      SummaryFooterField = 'ENE'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'ENE'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisFEB: TdxDBGridMaskColumn
      Caption = 'Feb'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'FEB'
      SummaryFooterType = cstSum
      SummaryFooterField = 'FEB'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'FEB'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisMAR: TdxDBGridMaskColumn
      Caption = 'Mar'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'MAR'
      SummaryFooterType = cstSum
      SummaryFooterField = 'MAR'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'MAR'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisABR: TdxDBGridMaskColumn
      Caption = 'Abr'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ABR'
      SummaryFooterType = cstSum
      SummaryFooterField = 'ABR'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'ABR'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisMAY: TdxDBGridMaskColumn
      Caption = 'May'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'MAY'
      SummaryFooterType = cstSum
      SummaryFooterField = 'MAY'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'MAY'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisJUN: TdxDBGridMaskColumn
      Caption = 'Jun'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'JUN'
      SummaryFooterType = cstSum
      SummaryFooterField = 'JUN'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'JUN'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisJUL: TdxDBGridMaskColumn
      Caption = 'Jul'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'JUL'
      SummaryFooterType = cstSum
      SummaryFooterField = 'JUL'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'JUL'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisAGO: TdxDBGridMaskColumn
      Caption = 'Ago'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'AGO'
      SummaryFooterType = cstSum
      SummaryFooterField = 'AGO'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'AGO'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisSEP: TdxDBGridMaskColumn
      Caption = 'Sep'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'SEP'
      SummaryFooterType = cstSum
      SummaryFooterField = 'SEP'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'SEP'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisOCT: TdxDBGridMaskColumn
      Caption = 'Oct'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'OCT'
      SummaryFooterType = cstSum
      SummaryFooterField = 'OCT'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'OCT'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisNOV: TdxDBGridMaskColumn
      Caption = 'Nov'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOV'
      SummaryFooterType = cstSum
      SummaryFooterField = 'NOV'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'NOV'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisDIC: TdxDBGridMaskColumn
      Caption = 'Dic'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DIC'
      SummaryFooterType = cstSum
      SummaryFooterField = 'DIC'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'DIC'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisTOT: TdxDBGridMaskColumn
      Caption = 'Total'
      DisableEditor = True
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'TOT'
      SummaryFooterType = cstSum
      SummaryFooterField = 'TOT'
      SummaryFooterFormat = '0'
      DisableFilter = True
      SummaryField = 'TOT'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisZona: TdxDBGridMaskColumn
      Caption = 'Zona'
      Width = 41
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ZONA'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
    object dbgrd_estadisNOMBRE: TdxDBGridMaskColumn
      Caption = 'Nombre Almacén'
      Width = 127
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOMBRE'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup3'
    end
    object dbgrd_estadisMarca: TdxDBGridMaskColumn
      Width = 60
      BandIndex = 0
      RowIndex = 0
      FieldName = 'Marca'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
    object dbgrd_estadisSITUACION: TdxDBGridMaskColumn
      Caption = 'Situación'
      Width = 25
      BandIndex = 0
      RowIndex = 0
      FieldName = 'Situacion'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
    object dbgrd_estadisDiary: TdxDBGridMaskColumn
      Sorted = csDown
      Width = 32
      BandIndex = 0
      RowIndex = 0
      FieldName = 'Diary'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
    object dbgrd_estadisgrupo: TdxDBGridMaskColumn
      Caption = 'Grupo'
      Width = 32
      BandIndex = 0
      RowIndex = 0
      FieldName = 'grupo'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
    object dbgrd_estadisProve: TdxDBGridMaskColumn
      Width = 32
      BandIndex = 0
      RowIndex = 0
      FieldName = 'Prove'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
    object dbgrd_estadislinea: TdxDBGridMaskColumn
      Caption = 'Línea'
      Width = 26
      BandIndex = 0
      RowIndex = 0
      FieldName = 'linea'
      SummaryGroupName = 'dbgrd_estadisSummaryGroup2'
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 878
    Height = 94
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 878
      Height = 60
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 93
        Height = 60
        Align = alLeft
        TabOrder = 0
        object chk_codigo: TCheckBox
          Left = 2
          Top = 17
          Width = 85
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Código'
          Checked = True
          State = cbChecked
          TabOrder = 0
          OnClick = chk_codigoClick
        end
        object edt_prcod: TEdit
          Left = 4
          Top = 35
          Width = 84
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 1
        end
      end
      object GroupBox2: TGroupBox
        Left = 342
        Top = 0
        Width = 74
        Height = 60
        Align = alLeft
        TabOrder = 4
        object edt_prgrp: TEdit
          Left = 2
          Top = 35
          Width = 67
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object chk_grupo: TCheckBox
          Left = 3
          Top = 17
          Width = 66
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Grupo'
          TabOrder = 1
          OnClick = chk_codigoClick
        end
      end
      object GroupBox5: TGroupBox
        Left = 184
        Top = 0
        Width = 84
        Height = 60
        Align = alLeft
        TabOrder = 2
        object edt_prsit: TEdit
          Left = 4
          Top = 35
          Width = 73
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object chk_situac: TCheckBox
          Left = 4
          Top = 17
          Width = 74
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Situación'
          TabOrder = 1
          OnClick = chk_codigoClick
        end
      end
      object GroupBox3: TGroupBox
        Left = 93
        Top = 0
        Width = 91
        Height = 60
        Align = alLeft
        TabOrder = 1
        object edt_prmarca: TEdit
          Left = 4
          Top = 35
          Width = 82
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object chk_marca: TCheckBox
          Left = 4
          Top = 17
          Width = 82
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Marca'
          TabOrder = 1
          OnClick = chk_codigoClick
        end
      end
      object GroupBox6: TGroupBox
        Left = 416
        Top = 0
        Width = 57
        Height = 60
        Align = alLeft
        TabOrder = 5
        object chk_prove: TCheckBox
          Left = 2
          Top = 17
          Width = 49
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Prove'
          TabOrder = 0
          OnClick = chk_codigoClick
        end
        object edt_prprove: TEdit
          Left = 5
          Top = 35
          Width = 46
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 1
        end
      end
      object GroupBox7: TGroupBox
        Left = 543
        Top = 0
        Width = 335
        Height = 60
        Align = alClient
        Caption = 'Zonas'
        TabOrder = 7
        object Label1: TLabel
          Left = 2
          Top = 18
          Width = 27
          Height = 13
          Caption = 'Inicial'
        end
        object Label2: TLabel
          Left = 7
          Top = 37
          Width = 22
          Height = 13
          Caption = 'Final'
        end
        object lkcmb_zonini: TDBLookupComboBox
          Left = 32
          Top = 12
          Width = 40
          Height = 21
          KeyField = 'ZONA'
          ListField = 'ZONA'
          ListSource = dts_zonini
          TabOrder = 0
        end
        object dbedt_zonini: TDBEdit
          Left = 73
          Top = 12
          Width = 262
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          DataField = 'NOMBRE'
          DataSource = dts_zonini
          TabOrder = 2
          OnDblClick = dbedt_zoniniDblClick
        end
        object lkcmb_zonfin: TDBLookupComboBox
          Left = 32
          Top = 35
          Width = 40
          Height = 21
          KeyField = 'ZONA'
          ListField = 'ZONA'
          ListSource = dts_zonfin
          TabOrder = 1
        end
        object DBEdit2: TDBEdit
          Left = 73
          Top = 35
          Width = 262
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          DataField = 'NOMBRE'
          DataSource = dts_zonfin
          TabOrder = 3
        end
      end
      object GroupBox8: TGroupBox
        Left = 473
        Top = 0
        Width = 70
        Height = 60
        Align = alLeft
        TabOrder = 6
        object chk_linea: TCheckBox
          Left = 3
          Top = 17
          Width = 62
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Línea'
          TabOrder = 0
          OnClick = chk_codigoClick
        end
        object edt_prlin: TEdit
          Left = 3
          Top = 35
          Width = 62
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 1
        end
      end
      object GroupBox4: TGroupBox
        Left = 268
        Top = 0
        Width = 74
        Height = 60
        Align = alLeft
        TabOrder = 3
        object edt_diary: TEdit
          Left = 2
          Top = 35
          Width = 67
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object chk_diary: TCheckBox
          Left = 3
          Top = 17
          Width = 66
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Diary'
          TabOrder = 1
          OnClick = chk_codigoClick
        end
      end
    end
    object Panel4: TPanel
      Left = 0
      Top = 60
      Width = 878
      Height = 34
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object Label19: TLabel
        Left = 213
        Top = 11
        Width = 36
        Height = 13
        Caption = 'del Año'
      end
      object Label18: TLabel
        Left = 6
        Top = 12
        Width = 73
        Height = 13
        Caption = 'Estadísticas de'
      end
      object btn_estadis: TBitBtn
        Left = 461
        Top = 6
        Width = 86
        Height = 25
        Caption = 'OK'
        Default = True
        ModalResult = 1
        TabOrder = 1
        OnClick = btn_estadisClick
        Glyph.Data = {
          DE010000424DDE01000000000000760000002800000024000000120000000100
          0400000000006801000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          3333333333333333333333330000333333333333333333333333F33333333333
          00003333344333333333333333388F3333333333000033334224333333333333
          338338F3333333330000333422224333333333333833338F3333333300003342
          222224333333333383333338F3333333000034222A22224333333338F338F333
          8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
          33333338F83338F338F33333000033A33333A222433333338333338F338F3333
          0000333333333A222433333333333338F338F33300003333333333A222433333
          333333338F338F33000033333333333A222433333333333338F338F300003333
          33333333A222433333333333338F338F00003333333333333A22433333333333
          3338F38F000033333333333333A223333333333333338F830000333333333333
          333A333333333333333338330000333333333333333333333333333333333333
          0000}
        NumGlyphs = 2
      end
      object cmb_tipoestadi: TComboBox
        Left = 85
        Top = 8
        Width = 118
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 0
        Items.Strings = (
          'Salidas Especiales'
          'Salidas x Venta'
          'Entradas x Cancel'
          'Entradas Especiales'
          'Salidas Mayoreo'
          'Entradas x Compra')
      end
      object BitBtn1: TBitBtn
        Left = 550
        Top = 6
        Width = 75
        Height = 25
        Caption = '&Título'
        TabOrder = 2
        OnClick = BitBtn1Click
        Kind = bkAll
      end
      object edt_anuestadis: TdxSpinEdit
        Left = 253
        Top = 8
        Width = 49
        TabOrder = 3
        Alignment = taRightJustify
        MaxValue = 2020
        MinValue = 1998
        Value = 2002
        StoredValues = 49
      end
      object chk_grpxalm: TCheckBox
        Left = 312
        Top = 9
        Width = 113
        Height = 17
        Caption = 'Agrupar x Almacén'
        Checked = True
        State = cbChecked
        TabOrder = 4
      end
    end
  end
  object qry_estadialm: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select alm, mes, nombre, sum(unidades) from estadis a'
      'join ptovta b on alm=clave and a.cia = b.cia'
      'where '
      '(tipo = :TIPO1 or tipo = :TIPO2) '
      'and anu = :ANU and codigo = :CODIGO and cia=:CIA'
      'group by alm,mes, nombre')
    Left = 244
    Top = 385
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_estadis: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select (codigo + alm) as llave, codigo, alm, '
      'null as maximo, null as costou, null as prlista,'
      
        'NULL as Ene, NULL as Feb, NULL as Mar, NULL as Abr, NULL as May,' +
        ' NULL as Jun, '
      
        'NULL as Jul, NULL as Ago, NULL as Sep, NULL as Oct, NULL as Nov,' +
        ' NULL as Dic, 0 as Tot, '
      'nombre, cast('#39'01'#39' as varchar(2)) as zona'
      
        'from estadis a join ptovta b on a.alm = b.clave and a.cia = b.ci' +
        'a'
      'where '
      
        '(tipo= :TIPO1 or tipo = :TIPO2) and anu = :ANU and codigo = :COD' +
        'IGO and a.cia = :CIA'
      
        'group by llave, codigo, alm, Ene, Feb, Mar, Abr, May, Jun, Jul, ' +
        'Ago, Sep, Oct, Nov, Dic, Tot, '
      'nombre, zona')
    UpdateObject = uqry_estadis
    Left = 275
    Top = 384
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_nombrestad: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select concepto, ncon from conceps where ncon = :IDCONCEPTO')
    Left = 242
    Top = 416
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDCONCEPTO'
        ParamType = ptUnknown
      end>
  end
  object dts_estadis: TDataSource
    AutoEdit = False
    DataSet = qry_estadis
    Left = 275
    Top = 416
  end
  object uqry_estadis: TUpdateSQL
    Left = 276
    Top = 354
  end
  object PopupMenu1: TPopupMenu
    Left = 120
    Top = 232
    object ExportaraExcel1: TMenuItem
      Caption = 'Exportar a ...'
      OnClick = ExportaraExcel1Click
    end
  end
  object dts_zonini: TDataSource
    DataSet = qry_zonini
    Left = 455
    Top = 272
  end
  object qry_zonini: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from zonainv order by zona')
    Left = 456
    Top = 240
  end
  object qry_zonfin: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from zonainv order by zona')
    Left = 488
    Top = 240
  end
  object dts_zonfin: TDataSource
    DataSet = qry_zonfin
    Left = 487
    Top = 272
  end
end
