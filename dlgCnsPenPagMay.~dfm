object frmDlgPendPagMay: TfrmDlgPendPagMay
  Left = 357
  Top = 162
  Width = 596
  Height = 498
  Caption = 'Pendientes Pago:'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object dbgrdPendPag: TdxDBGrid
    Left = 0
    Top = 0
    Width = 577
    Height = 426
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CONCEP'
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alTop
    TabOrder = 0
    OnKeyDown = dbgrdPendPagKeyDown
    DataSource = dtsPendpag
    Filter.Criteria = {00000000}
    LookAndFeel = lfFlat
    OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    object dbgrdPendPagDOCTO: TdxDBGridMaskColumn
      Alignment = taCenter
      Caption = 'Factura'
      Width = 50
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DOCTO'
    end
    object dbgrdPendPagPAGARE: TdxDBGridMaskColumn
      Alignment = taCenter
      Caption = 'Pagare'
      Width = 48
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PAGARE'
    end
    object dbgrdPendPagFECHA: TdxDBGridDateColumn
      Caption = 'Fecha'
      Width = 68
      BandIndex = 0
      RowIndex = 0
      FieldName = 'FECHA'
    end
    object dbgrdPendPagVENCE: TdxDBGridDateColumn
      Caption = 'Vencim.'
      Width = 68
      BandIndex = 0
      RowIndex = 0
      FieldName = 'VENCE'
    end
    object dbgrdPendPagIMPORTE: TdxDBGridCurrencyColumn
      Caption = 'Importe Ori.'
      Width = 79
      BandIndex = 0
      RowIndex = 0
      FieldName = 'IMPORTE'
    end
    object dbgrdPendPagSALDO: TdxDBGridCurrencyColumn
      Caption = 'Saldo'
      Color = clGray
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Width = 78
      BandIndex = 0
      RowIndex = 0
      FieldName = 'SALDO'
    end
    object dbgrdPendPagCONCEP: TdxDBGridMaskColumn
      Caption = 'Concepto'
      Width = 179
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CONCEP'
    end
    object dbgrdPendPagCONSE: TdxDBGridMaskColumn
      Alignment = taCenter
      Caption = 'Conse.'
      Visible = False
      Width = 66
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CONSE'
    end
  end
  object RzBitBtn1: TBitBtn
    Left = 341
    Top = 432
    Width = 110
    Height = 35
    Caption = '&Aceptar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = RzBitBtn1Click
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
      66666666666666666666666666666666666666666666666666666666AC666666
      66666666F86666666666666A22C666666666666F88866666666666A2222C6666
      666666F88888666666666A222222C66666666F888888866666666A22CA222C66
      66666F888F88886666666A2C66A222C666666F8866F8888666666AC6666A222C
      66666F86666F8888666666666666A222C66666666666F8888666666666666A22
      2C66666666666F8888666666666666A222C66666666666F8888666666666666A
      22C666666666666F8886666666666666A2C6666666666666F886666666666666
      6AC66666666666666F8666666666666666666666666666666666}
    NumGlyphs = 2
  end
  object btnCancelar: TBitBtn
    Left = 467
    Top = 432
    Width = 110
    Height = 35
    Caption = '&Cancelar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = btnCancelarClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
      6666666666666666666666666666666666666666666666666666666666666666
      6666666666666666666669000666669000666F88866666F88866691110666911
      10666F8888666F888866669111069111066666F88886F8888666666911101110
      6666666F88888888666666669111110666666666F88888866666666669111066
      666666666F888866666666669111110666666666F88888866666666911101110
      6666666F888888886666669111069111066666F88886F8888666691110666911
      10666F8888666F88886669999666669999666FFFF66666FFFF66666666666666
      6666666666666666666666666666666666666666666666666666}
    NumGlyphs = 2
  end
  object qsPendPag: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select docto, pagare, fecha, vence, importe, saldo, concep, cons' +
        'e'
      
        ' from movmay2 where mayoris = :Mayoris and coa = '#39'C'#39' and saldo >' +
        ' 0.05 and cia = :cia')
    Left = 112
    Top = 88
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'cia'
        ParamType = ptUnknown
      end>
  end
  object dtsPendpag: TDataSource
    DataSet = qsPendPag
    Left = 112
    Top = 120
  end
  object qsMayoris: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, nombre from mayoris where codigo = :Clave')
    Left = 72
    Top = 72
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Clave'
        ParamType = ptUnknown
      end>
  end
end
