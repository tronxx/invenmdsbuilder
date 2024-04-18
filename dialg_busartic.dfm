object dlg_busartic: Tdlg_busartic
  Left = 297
  Top = 135
  Width = 470
  Height = 361
  Caption = 'Búsqueda de artículos'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object pnl_articulo: TPanel
    Left = 0
    Top = 0
    Width = 454
    Height = 43
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 21
      Width = 33
      Height = 13
      Caption = '&Código'
      FocusControl = edt_codigo
    end
    object Label2: TLabel
      Left = 181
      Top = 23
      Width = 56
      Height = 13
      Caption = '&Descripción'
      FocusControl = edt_descri
    end
    object edt_codigo: TEdit
      Left = 48
      Top = 18
      Width = 121
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 0
      OnKeyDown = edt_codigoKeyDown
    end
    object edt_descri: TEdit
      Left = 243
      Top = 17
      Width = 206
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 1
      OnKeyDown = edt_descriKeyDown
    end
  end
  object dbgrd_inven: TdxDBGrid
    Left = 0
    Top = 43
    Width = 454
    Height = 238
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CODIGO'
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    TabOrder = 0
    OnKeyDown = dbgrd_invenKeyDown
    DataSource = dts_inven
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsBehavior = [edgoAutoSearch, edgoAutoSort, edgoDragScroll, edgoEditing, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseLocate]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    object dbgrd_invenCODIGO: TdxDBGridMaskColumn
      Caption = 'Código'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODIGO'
    end
    object dbgrd_invenDESCRI: TdxDBGridMaskColumn
      Caption = 'Descripción'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
    object dbgrd_invenPRECIO: TdxDBGridCurrencyColumn
      Caption = 'Precio'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PRECIO'
    end
    object dbgrd_invenEMPAQE: TdxDBGridMaskColumn
      Caption = 'Situación'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'EMPAQE'
    end
    object dbgrd_invenPIVA: TdxDBGridMaskColumn
      Caption = 'Iva'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PIVA'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 281
    Width = 454
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object BitBtn1: TBitBtn
      Left = 104
      Top = 6
      Width = 75
      Height = 25
      Caption = 'OK'
      ModalResult = 1
      TabOrder = 0
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
    object BitBtn2: TBitBtn
      Left = 224
      Top = 6
      Width = 75
      Height = 25
      TabOrder = 1
      Kind = bkCancel
    end
  end
  object qry_inven: TQuery
    CachedUpdates = True
    AfterScroll = qry_invenAfterScroll
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select codigo, descri, precio, empaqe, piva'
      'from inven'
      'where ( codigo like :CODIGO or descri like :DESCRI )'
      'and cia = :CIA'
      'and'
      '('
      '  (existes + existen between :EXIMIN and :EXIMAX)'
      ')'
      ''
      'order by codigo'
      ''
      ' '
      ' ')
    Left = 355
    Top = 204
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'DESCRI'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'EXIMIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'EXIMAX'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 315
    Top = 205
  end
end
