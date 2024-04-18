object Form_listpre2: TForm_listpre2
  Left = 193
  Top = 81
  Width = 789
  Height = 566
  Caption = 'Lista de Precios Elect.'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pnl_datos: TPanel
    Left = 0
    Top = 0
    Width = 773
    Height = 155
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Panel1: TPanel
      Left = 0
      Top = 0
      Width = 773
      Height = 93
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object GroupBox2: TGroupBox
        Left = 0
        Top = 0
        Width = 105
        Height = 93
        Align = alLeft
        Caption = 'Linea:'
        TabOrder = 0
        object lbl_linea: TLabel
          Left = 7
          Top = 12
          Width = 58
          Height = 13
          Caption = 'Línea Inicial'
        end
        object lbl_linea2: TLabel
          Left = 8
          Top = 51
          Width = 53
          Height = 13
          Caption = 'Línea Final'
        end
        object lkcmb_lineaini: TDBLookupComboBox
          Left = 8
          Top = 25
          Width = 62
          Height = 21
          DropDownWidth = 200
          KeyField = 'NUMERO'
          ListField = 'NUMERO'
          ListSource = dts_lineas
          TabOrder = 0
        end
        object lkcmb_lineafin: TDBLookupComboBox
          Left = 8
          Top = 65
          Width = 63
          Height = 21
          DropDownWidth = 200
          KeyField = 'NUMERO'
          ListField = 'NUMERO'
          ListSource = dts_lineas
          TabOrder = 1
        end
      end
      object GroupBox3: TGroupBox
        Left = 105
        Top = 0
        Width = 268
        Height = 93
        Align = alLeft
        Caption = 'Situacion:'
        TabOrder = 1
        object Label3: TLabel
          Left = 117
          Top = 11
          Width = 69
          Height = 13
          Caption = 'Situación Final'
        end
        object Label1: TLabel
          Left = 7
          Top = 12
          Width = 74
          Height = 13
          Caption = 'Situación Inicial'
        end
        object rbtn_mesta: TRadioButton
          Left = 10
          Top = 65
          Width = 121
          Height = 17
          Caption = 'Todas excepto éstas'
          Checked = True
          TabOrder = 2
          TabStop = True
        end
        object rbtn_estas: TRadioButton
          Left = 138
          Top = 65
          Width = 123
          Height = 17
          Caption = 'Sólo éstas'
          TabOrder = 3
        end
        object lkcmb_rematfin: TDBLookupComboBox
          Left = 112
          Top = 25
          Width = 100
          Height = 21
          DropDownWidth = 200
          KeyField = 'EMPAQE'
          ListField = 'EMPAQE'
          ListSource = dts_remates
          TabOrder = 1
        end
        object lkcmb_rematini: TDBLookupComboBox
          Left = 8
          Top = 25
          Width = 100
          Height = 21
          DropDownWidth = 200
          KeyField = 'EMPAQE'
          ListField = 'EMPAQE'
          ListSource = dts_remates
          TabOrder = 0
        end
      end
      object GroupBox4: TGroupBox
        Left = 373
        Top = 0
        Width = 88
        Height = 93
        Align = alLeft
        Caption = 'Costos'
        TabOrder = 3
        object rbtn_cost: TRadioButton
          Left = 8
          Top = 18
          Width = 75
          Height = 17
          Caption = 'Con Costo'
          TabOrder = 0
        end
        object rbtn_scost: TRadioButton
          Left = 8
          Top = 36
          Width = 75
          Height = 17
          Caption = 'Sin Costo'
          Checked = True
          TabOrder = 1
          TabStop = True
        end
      end
      object GroupBox8: TGroupBox
        Left = 461
        Top = 0
        Width = 166
        Height = 93
        Align = alLeft
        Caption = 'Xtensa/Combo'
        TabOrder = 4
        object rbtn_cprec: TRadioButton
          Left = 8
          Top = 18
          Width = 150
          Height = 17
          Caption = 'Con Combo'
          Checked = True
          TabOrder = 0
          TabStop = True
        end
        object rbtn_sprec: TRadioButton
          Left = 8
          Top = 36
          Width = 150
          Height = 17
          Caption = 'Sin Combo'
          TabOrder = 1
        end
      end
      object GroupBox5: TGroupBox
        Left = 627
        Top = 0
        Width = 124
        Height = 93
        Align = alLeft
        Caption = 'Tipo Listas de Precios:'
        TabOrder = 2
        Visible = False
        object rbtn_mds: TRadioButton
          Left = 8
          Top = 22
          Width = 113
          Height = 17
          Caption = 'Mds'
          Checked = True
          TabOrder = 0
          TabStop = True
        end
        object rbtn_electro: TRadioButton
          Left = 8
          Top = 42
          Width = 113
          Height = 17
          Caption = 'Electrohogar'
          TabOrder = 1
          Visible = False
        end
        object rbtn_ambos: TRadioButton
          Left = 8
          Top = 62
          Width = 113
          Height = 17
          Caption = 'Ambos'
          TabOrder = 2
          Visible = False
        end
      end
    end
    object Panel2: TPanel
      Left = 0
      Top = 93
      Width = 773
      Height = 62
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object grp_fecha: TGroupBox
        Left = 227
        Top = 0
        Width = 210
        Height = 62
        Align = alLeft
        Caption = 'Fecha:'
        TabOrder = 1
        object lbl_vigencia: TLabel
          Left = 9
          Top = 18
          Width = 103
          Height = 13
          Caption = 'Vigencia a Apartir del:'
        end
        object lbl_corte: TLabel
          Left = 10
          Top = 39
          Width = 94
          Height = 13
          Caption = 'Corte de Exitencias:'
        end
        object date_vigencia: TDateTimePicker
          Left = 115
          Top = 14
          Width = 90
          Height = 21
          CalAlignment = dtaLeft
          Date = 38762.7111857986
          Time = 38762.7111857986
          DateFormat = dfShort
          DateMode = dmComboBox
          Kind = dtkDate
          ParseInput = False
          TabOrder = 0
        end
        object date_corte: TDateTimePicker
          Left = 114
          Top = 37
          Width = 92
          Height = 21
          CalAlignment = dtaLeft
          Date = 38982.3491966782
          Time = 38982.3491966782
          DateFormat = dfShort
          DateMode = dmComboBox
          Kind = dtkDate
          ParseInput = False
          TabOrder = 1
        end
      end
      object GroupBox6: TGroupBox
        Left = 0
        Top = 0
        Width = 227
        Height = 62
        Align = alLeft
        Caption = 'Codigos:'
        TabOrder = 0
        object Label2: TLabel
          Left = 7
          Top = 18
          Width = 55
          Height = 13
          Caption = 'Del Codigo:'
        end
        object Label4: TLabel
          Left = 8
          Top = 39
          Width = 48
          Height = 13
          Caption = 'Al Codigo:'
        end
        object edt_codini: TEdit
          Left = 69
          Top = 14
          Width = 150
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object edt_codfin: TEdit
          Left = 69
          Top = 36
          Width = 150
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 1
          Text = 'ZZ'
        end
      end
      object GroupBox7: TGroupBox
        Left = 437
        Top = 0
        Width = 185
        Height = 62
        Align = alLeft
        Caption = 'Observaciones y Salto de Página'
        TabOrder = 2
        object ckb_obser: TCheckBox
          Left = 11
          Top = 16
          Width = 166
          Height = 16
          Caption = 'Imprimir las Observaciones'
          Checked = True
          State = cbChecked
          TabOrder = 0
        end
        object ckb_salto: TCheckBox
          Left = 11
          Top = 35
          Width = 158
          Height = 17
          Caption = 'Salto de Pagina x Linea'
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
      end
      object btn_imprel: TBitBtn
        Left = 678
        Top = 22
        Width = 77
        Height = 25
        Action = imprimir_lista
        Caption = 'Reporte'
        TabOrder = 3
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FF00FF000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000FF00FF0000000000BFBF
          BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
          BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF000000000000000000BFBF
          BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
          BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF0000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000000000FFFF
          FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
          FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF000000000000000000BFBF
          BF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBF
          BF00FFFFFF00BFBFBF00FFFFFF000000FF00FFFFFF000000000000000000FFFF
          FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
          FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF0000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF0000000000000000000000000000000000FFFF
          FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF00000000000000
          0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
          FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF0000000000BFBFBF00FFFFFF0000000000FFFF
          FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00000000000000000000000000000000000000000000000000FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      end
    end
  end
  object dbgrd_renglones: TdxDBGrid
    Left = 0
    Top = 155
    Width = 773
    Height = 372
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CODIGO'
    ShowGroupPanel = True
    ShowSummaryFooter = True
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    PopupMenu = PopupMenu1
    TabOrder = 1
    DataSource = dts_inven
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoIndicator, edgoRowSelect, edgoUseBitmap]
    OnCustomDraw = dbgrd_renglonesCustomDraw
    object dbgrd_renglonesCODIGO: TdxDBGridMaskColumn
      Caption = 'Codigo'
      Width = 120
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODIGO'
    end
    object dbgrd_renglonesDESCRI: TdxDBGridMaskColumn
      Caption = 'Descripcion'
      Width = 259
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
    object dbgrd_renglonesCOSTOS: TdxDBGridMaskColumn
      Caption = 'Costo'
      Width = 96
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COSTOS'
    end
    object dbgrd_renglonesLINEA: TdxDBGridMaskColumn
      Caption = 'Linea'
      Sorted = csUp
      Visible = False
      Width = 82
      BandIndex = 0
      RowIndex = 0
      FieldName = 'LINEA'
      GroupIndex = 0
    end
    object dbgrd_renglonesPIVA: TdxDBGridMaskColumn
      Caption = 'Iva'
      Width = 47
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PIVA'
    end
    object dbgrd_renglonesPRECIO: TdxDBGridMaskColumn
      Caption = 'Precio'
      Width = 101
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PRECIO'
    end
    object dbgrd_renglonesEMPAQE: TdxDBGridMaskColumn
      Caption = 'Empaque'
      Width = 112
      BandIndex = 0
      RowIndex = 0
      FieldName = 'EMPAQE'
    end
    object dbgrd_renglonesORDEN: TdxDBGridMaskColumn
      Caption = 'Oden'
      Width = 74
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ORDEN'
    end
    object dbgrd_renglonesGRUPO: TdxDBGridMaskColumn
      Caption = 'Grupo'
      Width = 97
      BandIndex = 0
      RowIndex = 0
      FieldName = 'GRUPO'
    end
  end
  object qry_delete: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'delete from inventmp ')
    Left = 104
    Top = 272
  end
  object qry_inven: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.codigo,cod2,a.descri,a.costos,a.linea,a.piva, c.idart,'
      'a.precio,a.precelec,a.empaqe,b.orden,e.codigo as grupo'
      'from inven a join lineas b on a.linea=b.numero and a.cia=b.cia'
      'join inv_invhist c on a.codigo = c.codigo and a.cia = c.cia'#9#9
      'join inv_relinv d on c.idart = d.idart and idrel = 1'
      'join inv_grupos e on d.iddato = e.idgrupo'
      'where'
      
        'a.linea between :LINEAINI and :LINEAFIN and a.empaqe not between' +
        ' :SITUAINI and :SITUAFIN'
      'and a.codigo between :CODINI and :CODFIN and a.cia= 1'
      ' ')
    Left = 104
    Top = 304
    ParamData = <
      item
        DataType = ftString
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SITUAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SITUAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODFIN'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 136
    Top = 304
  end
  object qry_inventmp: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from inventmp'
      ' ')
    UpdateObject = uqry_inventmp
    Left = 104
    Top = 337
  end
  object uqry_inventmp: TUpdateSQL
    ModifySQL.Strings = (
      'update inventmp'
      'set'
      '  CODIGO = :CODIGO,'
      '  COD2 = :COD2,'
      '  DESCRI = :DESCRI,'
      '  TIPO = :TIPO,'
      '  PROVE = :PROVE,'
      '  LINEA = :LINEA,'
      '  EMPAQE = :EMPAQE,'
      '  MINIMO = :MINIMO,'
      '  MAXIMO = :MAXIMO,'
      '  PRECIO = :PRECIO,'
      '  PIVA = :PIVA,'
      '  COSTOS = :COSTOS,'
      '  COSTON = :COSTON,'
      '  FECALTA = :FECALTA,'
      '  CIA = :CIA,'
      '  MDS = :MDS,'
      '  ELEC = :ELEC,'
      '  PRECELEC = :PRECELEC'
      'where'
      '  CODIGO = :OLD_CODIGO')
    InsertSQL.Strings = (
      'insert into inventmp'
      
        '  (CODIGO, COD2, DESCRI, TIPO, PROVE, LINEA, EMPAQE, MINIMO, MAX' +
        'IMO, '
      'PRECIO, '
      '   PIVA, COSTOS, COSTON, FECALTA, CIA, MDS, ELEC, PRECELEC)'
      'values'
      
        '  (:CODIGO, :COD2, :DESCRI, :TIPO, :PROVE, :LINEA, :EMPAQE, :MIN' +
        'IMO, '
      ':MAXIMO, '
      
        '   :PRECIO, :PIVA, :COSTOS, :COSTON, :FECALTA, :CIA, :MDS, :ELEC' +
        ', '
      ':PRECELEC)')
    DeleteSQL.Strings = (
      'delete from inventmp'
      'where'
      '  CODIGO = :OLD_CODIGO')
    Left = 137
    Top = 337
  end
  object qry_invorden: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'delete from inventmp ')
    Left = 104
    Top = 369
  end
  object qry_exist: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'delete from inventmp ')
    Left = 104
    Top = 400
  end
  object qry_plazmax: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'delete from inventmp ')
    Left = 104
    Top = 433
  end
  object qry_idart: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select idart from inv_invhist'
      'where codigo = :COD and cia = :CIA')
    Left = 104
    Top = 464
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'COD'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_linea: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select *  from lineas order by numero, orden')
    Left = 167
    Top = 272
  end
  object qry_obs: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select * from obslin where linea = :LINEA and moe = :MOE order b' +
        'y conse ')
    Left = 134
    Top = 272
    ParamData = <
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'MOE'
        ParamType = ptUnknown
      end>
  end
  object dts_lineas: TDataSource
    DataSet = qry_linea
    Left = 200
    Top = 272
  end
  object qry_remates: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select empaqe from inven group by empaqe')
    Left = 233
    Top = 272
  end
  object dts_remates: TDataSource
    DataSet = qry_remates
    Left = 265
    Top = 273
  end
  object PopupMenu1: TPopupMenu
    Left = 232
    Top = 368
    object Exportara1: TMenuItem
      Action = exportar
    end
  end
  object ActionList2: TActionList
    Images = dm.ImageList1
    Left = 664
    Top = 296
    object imprimir_lista: TAction
      Caption = 'Reporte'
      ImageIndex = 21
      OnExecute = imprimir_listaExecute
    end
    object exportar: TAction
      Caption = 'Eportar'
      ImageIndex = 9
      OnExecute = exportarExecute
    end
  end
  object qry_garantia: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select c.* from inv_invhist a join inv_relinv b'
      'on a.idart = b.idart'
      'join inv_garantias c on b.iddato = c.idgarantia'
      'where a.codigo = :COD and a.cia = :CIA and b.idrel= :IDREL'
      ''
      ' ')
    Left = 299
    Top = 273
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'COD'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IDREL'
        ParamType = ptUnknown
      end>
  end
  object qry_caracteristicas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.codigo, c.concep from inv_invhist a'
      'join inv_relinv b on a.idart = b.idart'
      'and b.idrel = :IDREL'
      'join inv_conceps c on b.iddato = idconcep'
      'where codigo = :COD'
      '')
    Left = 331
    Top = 273
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'COD'
        ParamType = ptUnknown
      end>
  end
  object qry_xtensa: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select b.* from inv_invhist a join inv_extensa'
      'b on a.idart = b.idart'
      'where a.codigo = :COD and a.cia= :CIA'
      '')
    Left = 363
    Top = 273
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'COD'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_buscaidart: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select b.* from inv_invhist a join inv_extensa'
      'b on a.idart = b.idart'
      'where a.codigo = :COD and a.cia= :CIA'
      '')
    Left = 395
    Top = 273
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'COD'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_plazoxarticulo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select plazomax from plazoscrd a join inv_invhist b'
      'on a.idlinea = b.idart'
      'where tipo= :TIPO and a.cia= :CIA'
      'and b.codigo = :CODIGO')
    Left = 171
    Top = 304
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end>
  end
  object qry_plazoxgrupo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select plazomax from plazoscrd a join inv_grupos b'
      'on a.idlinea = b.idgrupo'
      'where tipo= :TIPO and a.cia= :CIA'
      'and b.codigo = :CODIGO'
      ' ')
    Left = 204
    Top = 304
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end>
  end
  object qry_plazoxlin: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select tipo, plazomax from plazoscrd where linea= :LINEA and'
      
        '( tipo= :TIPO or tipo = :TIPO2 or tipo = :TIPO3 or tipo = :TIPO4' +
        ')'
      'and cia= :CIA')
    Left = 236
    Top = 304
    ParamData = <
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO3'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO4'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_plazoxprecio: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select plazomax from plazoscrd where tipo= :TIPO and cia= :CIA'
      '       and plistamax = ('
      '         select min(plistamax) from plazoscrd where tipo = :TIPO'
      '         and plistamax >= :PRECIO and cia= :CIA'
      '       )')
    Left = 266
    Top = 304
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PRECIO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
end
